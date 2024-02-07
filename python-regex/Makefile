# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=python-regex
PKG_VERSION:=2023.12.25
PKG_RELEASE:=1

PYPI_NAME:=regex
PKG_HASH:=29171aa128da69afdf4bde412d5bedc335f2ca8fcfe4489038577d05f16181e5

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
