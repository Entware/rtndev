#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-regex
PKG_VERSION:=2023.8.8
PKG_RELEASE:=2

PYPI_NAME:=regex
PKG_HASH:=fcbdc5f2b0f1cd0f6a56cdb46fe41d2cce1e644e3b68832f3eeebc5fb0f7712e

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
	DEPENDS:=+python3-light +python3-codecs +python3-urllib
endef

define Package/python3-regex/description
 This new regex implementation is intended eventually to replace Python’s
 current re module implementation.
endef

$(eval $(call Py3Package,python3-regex))
$(eval $(call BuildPackage,python3-regex))
