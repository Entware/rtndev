# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=python-regex
PKG_VERSION:=2026.9.29
PKG_RELEASE:=1

PYPI_NAME:=regex
PKG_HASH:=8b5fcc4771732191b2b7d1dd68d8f0353f47f8d90b6150f6dce58bf1112442cb

PKG_LICENSE:=Apache-2.0 CNRI-Python
PKG_LICENSE_FILES:=LICENSE.txt

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-regex
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=python-regexp
	URL:=https://github.com/mrabarnett/mrab-regex
	MAINTAINER:=Entware team, https://entware.net
	DEPENDS:=+python3-light +python3-codecs +python3-urllib
endef

define Package/python3-regex/description
 This new regex implementation is intended eventually to replace Python’s
 current re module implementation.
endef

$(eval $(call Py3Package,python3-regex))
$(eval $(call BuildPackage,python3-regex))
