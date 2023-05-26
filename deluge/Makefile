#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=deluge
PKG_VERSION:=2.1.1
PKG_RELEASE:=1

PYPI_NAME:=deluge
PKG_HASH:=d6ea7e1f5bdd75f40cbd1d56f0c97cd1b5b74bc9e03783858c7daa81063dd4b9

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/deluge/Default
	SUBMENU:=BitTorrent
	SECTION:=net
	CATEGORY:=Network
	TITLE:=a lightweight BitTorrent client
	URL:=https://deluge-torrent.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/deluge
	$(call Package/deluge/Default)
	TITLE+= (console UI & daemon)
	DEPENDS:= \
	    +python3-chardet \
	    +python3-ifaddr \
	    +python3-libtorrent \
	    +python3-mako \
	    +python3-pillow \
	    +python3-pyasn1 \
	    +python3-pyopenssl \
	    +python3-pyxdg \
	    +python3-rencode \
	    +python3-setproctitle \
	    +python3-setuptools \
	    +python3-twisted \
	    +python3-zope-interface
endef

define Package/deluge-ui-web
	$(call Package/deluge/Default)
	TITLE+= (Web UI)
	DEPENDS:=deluge
endef

define Package/deluge/description
 BitTorrent client with a client/server model.
endef

define Package/deluge/install
	$(INSTALL_DIR) $(1)$(PYTHON3_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON3_PKG_DIR)/* \
		$(1)$(PYTHON3_PKG_DIR)/
	rm -rf $(1)$(PYTHON3_PKG_DIR)/deluge/ui/{data,gtk3,web}
	$(SED) "s,save_config_path('deluge'),'/opt/etc/deluge'," \
		$(1)$(PYTHON3_PKG_DIR)/deluge/common.py

	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) \
	    $(PKG_INSTALL_DIR)/opt/bin/* \
		$(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S80deluged $(1)/opt/etc/init.d
	rm -rf $(1)/opt/bin/deluge-{gtk,web}
	$(call Python3/FixShebang,$(1)/opt/bin/* \
		$(1)$(PYTHON3_PKG_DIR)/deluge/path_*.py)
endef

define Package/deluge-ui-web/install
	$(INSTALL_DIR) $(1)$(PYTHON3_PKG_DIR)/deluge/ui
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON3_PKG_DIR)/deluge/ui/{data,web} \
		$(1)$(PYTHON3_PKG_DIR)/deluge/ui/

	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) \
	    $(PKG_INSTALL_DIR)/opt/bin/deluge-web \
		$(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S81deluge-web $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/deluge-web-reset_password $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/deluge/state
	$(call Python3/FixShebang,$(1)/opt/bin/*)
endef

define Package/deluge/postinst
#!/bin/sh
if [ ! -f /opt/etc/deluge/.configured ]; then
  echo "Setting default deluge ui to console ... "
  /opt/bin/deluge -s console
  touch /opt/etc/deluge/.configured
fi
endef

$(eval $(call Py3Package,deluge))
$(eval $(call BuildPackage,deluge))

$(eval $(call Py3Package,deluge-ui-web))
$(eval $(call BuildPackage,deluge-ui-web))
