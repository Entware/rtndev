#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-regex
PKG_VERSION:=2022.7.9
PKG_RELEASE:=1

PYPI_NAME:=regex
PKG_HASH:=601c99ac775b6c89699a48976f3dbb000b47d3ca59362c8abc9582e6d0780d91

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-regex
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=python-regexp
	URL:=https://bitbucket.org/mrabarnett/mrab-regex
	MAINTAINER:=Entware team, https://entware.net
	DEPENDS:=+python3-light
endef

define Package/python3-regex/description
 This new regex implementation is intended eventually to replace Python’s
 current re module implementation.
endef

$(eval $(call Py3Package,python3-regex))
$(eval $(call BuildPackage,python3-regex))
