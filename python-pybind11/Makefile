# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025-2026 Entware

# as deps (pillow)

include $(TOPDIR)/rules.mk

PKG_NAME:=pybind11
PKG_VERSION:=2.13.6
PKG_RELEASE:=1

PYPI_NAME:=pybind11
PKG_HASH:=ba6af10348c12b24e92fa086b39cfba0eff619b61ac77c406167d813b096d39a

PKG_LICENSE:=BSD-3-Clause
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Entware team, https://entware.net

HOST_BUILD_DEPENDS:=python-setuptools/host python-wheel/host
PKG_BUILD_DEPENDS:=$(HOST_BUILD_DEPENDS)

PKG_HOST_ONLY:=1

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-host-build.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-pybind11
  SECTION:=lang
  CATEGORY:=Languages
  SUBMENU:=Python
  TITLE:=Seamless operability between C++11 and Python
  URL:=https://github.com/pybind/pybind11
  DEPENDS:=+python3
  BUILDONLY:=1
endef

define Package/python3-pybind11/description
 pybind11 is a lightweight header-only library that exposes C++
 types in Python and vice versa, mainly to create Python bindings of existing
 C++ code.
endef

$(eval $(call HostBuild))
$(eval $(call Py3Package,python3-pybind11))
$(eval $(call BuildPackage,python3-pybind11))
#$(eval $(call BuildPackage,python3-pybind11-src))
