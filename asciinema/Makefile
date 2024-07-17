# SPDX-License-Identifier: AGPL-3.0-or-later
#
# Copyright (C) 2011-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=asciinema
PKG_VERSION:=2.4.0
PKG_RELEASE:=2

PYPI_NAME:=asciinema
PKG_HASH:=828e04c36ba622a7b8f8f912c8f0c1329538b6c7ed1c0d1b131bbbfe3a221707

PKG_BUILD_DEPENDS:=python-wheel/host

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/asciinema
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Terminal
	DEPENDS:=+ncurses-bin +python3-codecs +python3-multiprocessing +python3-urllib +python3-uuid
	TITLE:=A terminal sessions recorder
	URL:=https://asciinema.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/asciinema/description
 asciinema lets you record your terminal sessions and share it with other geeks.
endef

define Package/asciinema/conffiles
/opt/etc/asciinema/config
endef

$(eval $(call Py3Package,asciinema))
$(eval $(call BuildPackage,asciinema))
