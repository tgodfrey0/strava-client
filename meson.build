project('strava-client', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

gtkmm_dep = dependency('gtkmm-4.0', version: '>= 4.6.0')
boost_dep = dependency('boost', modules : ['log'])
oatpp_dep = dependency('oatpp')

subdir('src')
incs = include_directories('include')
libs = include_directories('lib')

exe = executable('strava_client', sources,
  dependencies: [gtkmm_dep, boost_dep, oatpp_dep],
  include_directories : [incs, libs],
  win_subsystem: 'windows',
)

test('basic', exe)
